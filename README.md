# SOCI-enabled C++ project with PostgreSQL Database Included

This is a docker devcontainer that installs SOCI for use with C++ and PostgreSQL. The container contains a PostgreSQL database as well and is therefore a fully integrated solution for development of PostgreSQL with SOCI. The purpose of this devcontainer is to enable simple testing of the database and the development with SOCI, without having to set up a [Docker Compose](https://docs.docker.com/compose/) network.

## How to compile and run

1. Create and go into the build folder.

```bash
mkdir build/ && cd build/
```
2. Run CMake to generate Makefiles.

```bash
cmake ..
```

3. Run Make to generate the target.

```bash
make 
```

4. You can now run your compiled target file.

```bash
./soci-dev
```

## Issues
If you run into issues with CMake cache errors, try deleting the build folder and go through the steps again.

## Other Databases
You can use this container to develop for other databases than PostgreSQL as well, like MySQL, SQLite3, Firebird, DB2, Oracle or different ones using ODBC API.  To do this, see the [Installation](http://soci.sourceforge.net/doc/release/4.0/installation/) guide on [SOCI (4.2.0) documentation](http://soci.sourceforge.net/doc/release/4.0/). Then change the parameters in the [Dockerfile](https://github.com/mariugul/soci-devcontainer/blob/main/.devcontainer/Dockerfile) accordingly. You might also need to install new libraries for the specific backend of your choice as you can see by viewing the [backend page](http://soci.sourceforge.net/doc/release/4.0/backends/) for your specific database choice.
