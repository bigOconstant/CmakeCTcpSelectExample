FROM registry.access.redhat.com/ubi8/ubi:latest

RUN yum install git -y
RUN yum install gcc -y
RUN yum install gcc-c++ -y
RUN yum install make -y
RUN yum install cmake -y

WORKDIR /app

COPY . .

RUN rm -rf build

RUN git submodule update --recursive --remote

WORKDIR /app/build

RUN cmake ..

RUN make

RUN cp ../config.txt config.txt

EXPOSE 5000/tcp

EXPOSE 5001/tcp

RUN pwd;ls

ENTRYPOINT /app/build/server