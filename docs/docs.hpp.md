[Index](index.hpp.md#index)

# Editing documentation

All documents in the docs/ directory are generated with [docgen](https://github.com/xenris/docgen)
using the command "docgen -d $(find . -regex '.+\..pp')". To modify documents find their
equivalent .hpp file, modify that, then run docgen.
