SRC=$1
rm test.run
g++ -g $SRC -o test.run
./test.run
