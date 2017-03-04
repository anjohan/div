pdftoppm $1.pdf $1
for fil in `ls $1-*.ppm`;
do
    convert $fil -brightness-contrast 0x20 $fil
    potrace -b pdf -k 0.7 -C#0000FF $fil
done
pdfjoin $1-*.pdf --rotateoversize 'false' --outfile $1_vektorisert.pdf
rm $1-*.*
