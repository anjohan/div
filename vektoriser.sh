pdftoppm $1.pdf $1
for fil in `ls $1-*.ppm`;
do
    convert $fil -brightness-contrast 0x20 $fil
    potrace -b pdf -k 0.8 -C#0000FF $fil
done
pdfjoin $2.pdf $1-*.pdf --rotateoversize 'false' --outfile $2.pdf
rm $1-*.*
