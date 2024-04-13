FROM ubuntu:latest
WORKDIR /usr/src/docker_2
COPY . /usr/src/docker_2
RUN apt update && apt install -y g++ clang vim \
    && g++ -o gcc_cpp mainGCC.cpp \
    && clang -o clang_cpp mainClang.cpp -lstdc++
CMD ["sh", "-c", "./gcc_cpp && ./clang_cpp"]
