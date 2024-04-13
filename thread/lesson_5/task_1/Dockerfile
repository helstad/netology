FROM ubuntu:latest
WORKDIR /usr/src/docker_1
COPY . /usr/src/docker_1
RUN apt update && apt install -y g++ vim
ADD Test.cpp /usr/src/docker_1/
RUN g++ Test.cpp -o Test
CMD ["./Test"]
