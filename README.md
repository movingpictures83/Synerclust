# SynerClust
# Language: C++
# Input: TXT
# Output: DIRECTORY
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: SynerClust 1, Python 2.7

PluMA plugin to interface to the SynerClust (Georgescu et al, 2018) orthologue clustering tool.

The plugin accepts as input a TXT file of keyword-value pairs (tab-delimited):

catalog: Data catalog file (TXT)
tree: Tree file (NWK)

The output parameter is a directory, which should be your current working directory.  All output files
are however copied into the Prefix directory upon completion.

