
python preprocess.py $2 $3
make
./a.out
python postprocess.py
cd data
mkdir $1
cd ../
mv *.txt *.gif *.csv ./data/$1