use std::io;

use structopt::StructOpt;

use converters::json2sbp;

#[cfg(all(not(windows), not(target_env = "musl")))]
#[global_allocator]
static ALLOC: jemallocator::Jemalloc = jemallocator::Jemalloc;

/// Convert SBP JSON data to binary SBP.
///
/// Typical usage:
///
///     cat sbp.json | json2sbp
#[derive(Debug, StructOpt)]
#[structopt(name = "json2sbp", verbatim_doc_comment)]
struct Options {
    /// Print debugging messages to standard error
    #[structopt(long)]
    debug: bool,

    /// Flush output on every message
    #[structopt(long = "unbuffered")]
    unbuffered: bool,
}

fn main() -> sbp::Result<()> {
    let options = Options::from_args();

    if options.debug {
        std::env::set_var("RUST_LOG", "debug");
    }

    env_logger::init();

    let stdin = io::stdin();
    let stdout = io::stdout();

    let unbuffered = atty::is(atty::Stream::Stdout) || options.unbuffered;

    json2sbp(stdin, stdout, unbuffered)
}
