use std::env;
use std::path::PathBuf;
use walkdir::WalkDir;

fn compile_libunwind() {
    let mut cfg = cc::Build::new();
    cfg.warnings(false);
    cfg.cpp_set_stdlib(None);
    cfg.cpp(true);
    cfg.flag("-std=c++11");
    cfg.flag("-fno-exceptions");
    cfg.flag("-fno-rtti");
    cfg.flag("-fstrict-aliasing");
    cfg.flag("-fvisibility=hidden");
    cfg.flag("-funwind-tables");
    cfg.define("_LIBUNWIND_NO_HEAP", None);
    cfg.define("_LIBUNWIND_IS_BAREMETAL", None);
    cfg.define("_LIBUNWIND_IS_NATIVE_ONLY", None);
    cfg.define("_LIBUNWIND_HAS_NO_THREADS", None);
    cfg.define("NDEBUG", None);
    cfg.include("llvm-libunwind/include");
    cfg.include("include");

    let libunwind_sources = [
        "llvm-libunwind/src/UnwindRegistersRestore.S",
        "llvm-libunwind/src/UnwindRegistersSave.S",
        "llvm-libunwind/src/libunwind.cpp",
        // Needed on ARM targets for EHABI unwinding
        "llvm-libunwind/src/Unwind-EHABI.cpp",
    ];
    for source in &libunwind_sources {
        cfg.file(source);
    }

    cfg.compile("llvm_libunwind");
}

fn gen_libunwind_bindings() {
    let args = vec![
        "-nostdlibinc".to_string(),
        "-ffreestanding".to_string(),
        "-I".to_string(),
        "llvm-libunwind/include".to_string(),
        "-I".to_string(),
        "external/riscv64_elf_toolchain/riscv/riscv64-unknown-elf/include/".to_string(),
        "-D_LIBUNWIND_IS_NATIVE_ONLY".to_string(),
    ];

    let bindings = bindgen::Builder::default()
        .header("llvm-libunwind/include/libunwind.h")
        .use_core()
        .ctypes_prefix("::cty")
        .prepend_enum_name(false)
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .clang_args(&args)
        //.generate()
        .dump_preprocessed_input()
        .expect("Unable to generate bindings");

//    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
//    bindings
//        .write_to_file(out_path.join("bindings.rs"))
//        .expect("Couldn't write bindings!");
}

fn main() {
    let ev = env::vars();
    println!("ENV variables");
    for (k,v) in ev.into_iter() {
        println!("{k}<=>{v}");
    }
    println!("ENV variables end");

    println!("+=++=++=++=++=++=++=+=======");
    compile_libunwind();
    println!("+=++=++=++=++=++=++=+=======");
    gen_libunwind_bindings();
    println!("+=++=++=++=++=++=++=+=======");

    for entry in WalkDir::new("llvm-libunwind")
        .into_iter()
        .chain(WalkDir::new("include").into_iter())
    {
        println!(
            "cargo:rerun-if-changed={}",
            entry.unwrap().path().to_str().unwrap()
        );
    }
}
