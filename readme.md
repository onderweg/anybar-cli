# Anybar-cli

A minimal C command line client for [AnyBar](https://github.com/tonsky/AnyBar).

## Usage

	anybar-cli <command> [port]

By default, `anybar-cli` assumes that Anybar is bound to localhost on UDP port `1738`.	

Examples:

    $ anybar-cli red    
    $ anybar-cli green    
    $ anybar-cli blue    
    $ anybar-cli exclamation
    $ anybar-cli orange 1740 # use port 1740 instead of the default
