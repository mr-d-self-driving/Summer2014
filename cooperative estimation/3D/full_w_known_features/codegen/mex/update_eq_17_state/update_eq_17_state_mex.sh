MATLAB="/usr/local/MATLAB/MATLAB_Production_Server/R2013a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/tim/.matlab/R2013a"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for update_eq_17_state" > update_eq_17_state_mex.mki
echo "CC=$CC" >> update_eq_17_state_mex.mki
echo "CFLAGS=$CFLAGS" >> update_eq_17_state_mex.mki
echo "CLIBS=$CLIBS" >> update_eq_17_state_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> update_eq_17_state_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> update_eq_17_state_mex.mki
echo "CXX=$CXX" >> update_eq_17_state_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> update_eq_17_state_mex.mki
echo "CXXLIBS=$CXXLIBS" >> update_eq_17_state_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> update_eq_17_state_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> update_eq_17_state_mex.mki
echo "LD=$LD" >> update_eq_17_state_mex.mki
echo "LDFLAGS=$LDFLAGS" >> update_eq_17_state_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> update_eq_17_state_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> update_eq_17_state_mex.mki
echo "Arch=$Arch" >> update_eq_17_state_mex.mki
echo OMPFLAGS= >> update_eq_17_state_mex.mki
echo OMPLINKFLAGS= >> update_eq_17_state_mex.mki
echo "EMC_COMPILER=" >> update_eq_17_state_mex.mki
echo "EMC_CONFIG=optim" >> update_eq_17_state_mex.mki
"/usr/local/MATLAB/MATLAB_Production_Server/R2013a/bin/glnxa64/gmake" -B -f update_eq_17_state_mex.mk
