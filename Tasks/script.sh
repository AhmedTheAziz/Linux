#! bin/bash

#1.0- create a directory [Dip]
#echo "Welcome to Task02 Please enter the name of the directory.."
Dir=~/Documents/Robotics-Corner/Tasks/Task02/DIP
#read Dir
#1.1- if condition to make sure that the Dir dosen't exist then create it.
if [ ! -d /$Dir ]; then
 mkdir  $Dir
 echo " $Dir is Created.";
else
echo " $Dir already exists ";
fi

#1.2- open Dir.
cd $Dir

#2.0- creat 5 file [F1,F2,F3,F4,F5]
touch F1.txt F2.txt F3.txt F4.txt F5.txt

#2.1- list files
pwd
ls -l
#3.0- script that :
touch shell1.sh
pwd
ls -l
cd .. > shell1.sh 
pwd
ls -l
rm -rf $Dir >> script.sh
pwd
ls -l

