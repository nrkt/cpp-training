FROM ubuntu:20.04

# some of the `apt-get` installs are interactive and require configuration
ENV DEBIAN_FRONTEND=noninteractive

# install c++
RUN apt-get update && \
    apt-get install -y build-essential cmake clang libssl-dev vim

# install bazel
RUN apt install -y curl && \
    apt-get update && \
    apt-get install -y sudo && \
    sudo apt-get install -y gnupg && \
    sudo apt-get install -y kgpg && \
    curl https://bazel.build/bazel-release.pub.gpg | sudo apt-key add - && \
    echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list && \
    apt update && apt install -y bazel

# # install git
RUN sudo apt-get install -y git

# install google test
# RUN apt-get install -y wget && \
#     cd /tmp && \
#     wget https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz && \
#     tar zxvf release-1.11.0.tar.gz && \
#     mkdir -p /usr/local/src && \
#     sudo mv googletest-release-1.11.0 /usr/local/src && \
#     cd /usr/local/src/googletest-release-1.11.0 && \
#     mkdir build && \
#     cd build && \
#     cmake .. && \
#     make && \
#     sudo make install
