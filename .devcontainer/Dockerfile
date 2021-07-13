# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.183.0/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="ubuntu-20.04"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    # Needed for PostgreSQL backend in SOCI
    libpq-dev postgresql-server-dev-all postgresql

# Build and install SOCI
RUN mkdir /soci-build && cd /soci-build && git clone git://github.com/SOCI/soci.git && \
    mkdir /soci-build/build && \
    cd /soci-build/build && \
    sudo cmake -G "Unix Makefiles" -DSOCI_CXX11=ON -DWITH_POSTGRESQL=ON -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql/ ../soci && \
    sudo make && \
    sudo make install 