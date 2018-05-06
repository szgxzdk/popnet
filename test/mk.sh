x=0
while [ $x -lt 8 ]; do
    y=0
    while [ $y -lt 8 ]; do
        touch "trace.${x}.${y}"
        let 'y+=1'
    done
    let 'x+=1'
done
