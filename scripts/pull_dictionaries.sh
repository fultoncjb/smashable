
bin_dir=$1

if [ ! -d $bin_dir ]; then
    mkdir $bin_dir
fi
if [ ! -f $bin_dir/en_US.aff ]; then
   curl -o $bin_dir/en_US.aff https://cgit.freedesktop.org/libreoffice/dictionaries/plain/en/en_US.aff?id=a4473e06b56bfe35187e302754f6baaa8d75e54f
fi
if [ ! -f $bin_dir/en_US.dic ]; then
    curl -o $bin_dir/en_US.dic https://cgit.freedesktop.org/libreoffice/dictionaries/plain/en/en_US.dic?id=a4473e06b56bfe35187e302754f6baaa8d75e54f
fi
