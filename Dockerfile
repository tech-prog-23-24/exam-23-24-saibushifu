FROM ubuntu
LABEL author="Kostin Dmitrii Vladimirovich"
RUN apt-get update
RUN apt install -y gcc qtcreator qtbase5-dev qt5-qmake cmake
COPY . MyProj_Kostin_231_351
RUN apt install -y g++
RUN qmake MyProj_Kostin_231_351/FilmDbApp.pro
RUN make
CMD ./FilmDbApp 0