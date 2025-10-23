# json-extract
this program allows you to very quickly turn an automatically generated, barely human-readable json into a fully formatted, easy to read json file.
This program is very simple and can thus be used really quickly and effectively. All you need to do to use the program, is to type in the filename of the json you want to format as a command line argument, and you're done.
The program will write to "extract[filename]". So if you're trying to convert a file called "names.json", the program would write to "extractnames.json". And that's really all. More features might be added later, but don't expect it. Happy json reading!

# build information

this is information useful for if you want to build the program yourself.

- this program is dependent on nlohmann's json library. It is very simple to install, and very useful. If you want to build this program, you need to have that library.