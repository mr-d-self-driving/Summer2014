MATLAB="/usr/local/MATLAB/MATLAB_Production_Server/R2013a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/tim/.matlab/R2013a"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for ukf_update_10_state" > ukf_update_10_state_mex.mki
echo "CC=$CC" >> ukf_update_10_state_mex.mki
echo "CFLAGS=$CFLAGS" >> ukf_update_10_state_mex.mki
echo "CLIBS=$CLIBS" >> ukf_update_10_state_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> ukf_update_10_state_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> ukf_update_10_state_mex.mki
echo "CXX=$CXX" >> ukf_update_10_state_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> ukf_update_10_state_mex.mki
echo "CXXLIBS=$CXXLIBS" >> ukf_update_10_state_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> ukf_update_10_state_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> ukf_update_10_state_mex.mki
echo "LD=$LD" >> ukf_update_10_state_mex.mki
echo "LDFLAGS=$LDFLAGS" >> ukf_update_10_state_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> ukf_update_10_state_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> ukf_update_10_state_mex.mki
echo "Arch=$Arch" >> ukf_update_10_state_mex.mki
echo OMPFLAGS= >> ukf_update_10_state_mex.mki
echo OMPLINKFLAGS= >> ukf_update_10_state_mex.mki
echo "EMC_COMPILER=" >> ukf_update_10_state_mex.mki
echo "EMC_CONFIG=optim" >> ukf_update_10_state_mex.mki
"/usr/local/MATLAB/MATLAB_Production_Server/R2013a/bin/glnxa64/gmake" -B -f ukf_update_10_state_mex.mk
