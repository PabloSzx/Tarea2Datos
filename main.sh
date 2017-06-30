make
for (( c=10000; c<=1000000; c = c + 10000 ))
do
  echo "Ejecucion con n = $c"
  ./main $c
done
