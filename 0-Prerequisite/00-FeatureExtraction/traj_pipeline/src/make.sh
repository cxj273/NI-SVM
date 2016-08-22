cd ./fisher_pipe
bash make.sh
cp fisher ../../bin/fisher
cd ..
cd ./fv_ensemble
make clean
make
cp extract_fv ../../bin/extract_fv
cd ..
cd ./fv_ensemble_xyt
make clean
make
cp extract_fv_xyt ../../bin/extract_fv_xyt
cd ..
cd improved_trajectory_release/
make clean
make
cp ./release/DenseTrackStab ../../bin/DenseTrackStab
cd ../../improved_trajectory_release_skip3/src
make clean
make
cp ./release/DenseTrackStab ../../bin/DenseTrackStab_skip3
cd ../../improved_trajectory_release_skip6/src
make clean
make
cp ./release/DenseTrackStab ../../bin/DenseTrackStab_skip6
cd ..
