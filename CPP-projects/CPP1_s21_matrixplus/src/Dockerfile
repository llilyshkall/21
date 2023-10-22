FROM ubuntu:22.04
WORKDIR /src
COPY Makefile .
COPY s21_matrix_oop.h .
COPY s21_matrix_oop.cc .
COPY tests ./tests

RUN apt-get update && \
    apt-get -y upgrade && \
    apt-get install -y g++ make libgtest-dev valgrind

CMD ["make", "leaks"]