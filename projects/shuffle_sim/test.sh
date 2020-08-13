#!/bin/sh
RUNS=10
PASS=100
retVal=0
for i in `seq 0 $RUNS`; do
  seed=$((i*PASS))
  echo "starting $seed"
  ./all "$seed"
  process_id=$!
  retVal=$?
  if [ $retVal -ne 0 ]; then
     echo "Error seed = $i" > error_seed
     echo "Error seed = $i"
     exit $retVal
  fi

  for j in `seq 1 $PASS`; do
    seed=$((i*PASS+j))
    ./all "$seed"
    retVal=$?
    if [ $retVal -ne 0 ]; then
      echo "Error seed = $i" > error_seed
      echo "Error seed = $i"
  	  exit $retVal
    fi
  done
  #sleep 0.5
done

echo "starting benchmark:"
start_time=$(($(date +%s%N)/1000000))

for i in `seq 0 $RUNS`; do
  seed=$((i*PASS))
  ./all "$seed" -noVerify

  for j in `seq 1 $PASS`; do
    seed=$((i*PASS+j))
    ./all "$seed" -noVerify
  done
  #sleep 0.5
done
end_time=$(($(date +%s%N)/1000000))
echo execution time was `expr $end_time - $start_time` ms.
