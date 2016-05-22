#README

A minimal C command line client for [AnyBar](https://github.com/tonsky/AnyBar).

## Usage

By default, anybar-cli assumes that Anybar is bound to localhost on UDP port 1738.

	anybar-cli <command> [port]

Examples:

    $ anybar-cli red    
    $ anybar-cli green    
    $ anybar-cli blue    
    $ anybar-cli exclamation
    $ anybar-cli orange 1740 # use port 1740