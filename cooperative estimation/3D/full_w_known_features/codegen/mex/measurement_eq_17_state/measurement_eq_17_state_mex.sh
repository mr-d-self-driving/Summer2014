MATLAB="/usr/local/MATLAB/MATLAB_Production_Server/R2013a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/tim/.matlab/R2013a"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for measurement_eq_17_state" > measurement_eq_17_state_mex.mki
echo "CC=$CC" >> measurement_eq_17_state_mex.mki
echo "CFLAGS=$CFLAGS" >> measurement_eq_17_state_mex.mki
echo "CLIBS=$CLIBS" >> measurement_eq_17_state_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> measurement_eq_17_state_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> measurement_eq_17_state_mex.mki
echo "CXX=$CXX" >> measurement_eq_17_state_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> measurement_eq_17_state_mex.mki
echo "CXXLIBS=$CXXLIBS" >> measurement_eq_17_state_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> measurement_eq_17_state_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> measurement_eq_17_state_mex.mki
echo "LD=$LD" >> measurement_eq_17_state_mex.mki
echo "LDFLAGS=$LDFLAGS" >> measurement_eq_17_state_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> measurement_eq_17_state_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> measurement_eq_17_state_mex.mki
echo "Arch=$Arch" >> measurement_eq_17_state_mex.mki
echo OMPFLAGS= >> measurement_eq_17_state_mex.mki
echo OMPLINKFLAGS= >> measurement_eq_17_state_mex.mki
echo "EMC_COMPILER=" >> measurement_eq_17_state_mex.mki
echo "EMC_CONFIG=optim" >> measurement_eq_17_state_mex.mki
"/usr/local/MATLAB/MATLAB_Production_Server/R2013a/bin/glnxa64/gmake" -B -f measurement_eq_17_state_mex.mk
