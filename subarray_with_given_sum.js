//A common problem to be found but I do it with Javascript

function subarray_sum(array,K){

  let curr_sum = 0, start = 0,  i;
  
  for (i=0 ; i<array.length; ++i) {

    if(curr_sum < K)
      { curr_sum = curr_sum + array[i]; }
    
    while(curr_sum > K && start<i)
      { curr_sum = curr_sum - array[start];
        ++start;  }

    if(curr_sum === K)
      { console.log(array.slice(start,i+1));
        return; }
  
 }

  console.log("No sub array found");
}

//for test only
subarray_sum([2,1,2,3,4,5,6,3],5);