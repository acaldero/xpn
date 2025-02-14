
set -x
set -e

cd build

cmake -S .. -B . -D BUILD_TESTS=true -D CMAKE_INSTALL_PREFIX=$1 -D CMAKE_C_COMPILER=/home/lab/bin/mpich/bin/mpicc -D CMAKE_CXX_COMPILER=/home/lab/bin/mpich/bin/mpic++ -D ENABLE_FABRIC_SERVER=/home/lab/bin/libfabric

cmake --build . -j 8

cmake --install .