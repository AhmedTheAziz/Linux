#!/bin/bash

echo "choose the name of the Directory, please!!"
read dir
if [ ! -d $dir ]; then
mkdir $dir

else 
echo "exists"

fi
cd $dir
pwd
 for i in {1..5}; do
if [ ! -e f$i ]; then 
touch f$i.txt
echo "file has been created!!" 
else 
echo "file already exists!!"
fi ; sleep 1; done

ls -l
