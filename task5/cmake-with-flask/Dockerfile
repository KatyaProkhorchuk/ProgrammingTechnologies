FROM gcc:latest as build
WORKDIR opt/techprog
RUN apt-get update &&\
     apt-get install -y cmake build-essential python3 python3-pip
RUN apt-get install -y tzdata
RUN apt-get -y install python3
RUN pip3 install --upgrade pip
COPY . /opt/techprog
WORKDIR /opt/techprog
RUN cmake . && make && ./bin/C


FROM python:3 as builder
WORKDIR /opt/techprog
RUN python3 -m pip install flask


COPY --from=build /opt/techprog .
RUN useradd -ms /bin/bash tp2022user
USER tp2022user
EXPOSE 8898

CMD python3 app.py --port=8898 --host="0.0.0.0"
