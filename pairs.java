import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     ******HackerRank Problem Solving practice*******
     * 17/17 testcases AC
     * Two-pointer approach
     */
    public static int pairs(int k, List<Integer> arr) {
        int n = arr.size();
        Collections.sort(arr); //sorting the array first
        
        int left=0,right=1;  //one pointer "right" alway run ahead the other "left"
        int ret=0;
        
        while(right<n && left<n){ 
            int diff = arr.get(right)-arr.get(left);
            if(diff>k){
                ++left;  //Dont need to get the "right"  back because the previous position is sure to have smaller difference
            }
            else if(diff<k){
                ++right;
            }
            else if(diff==k){   
                ++ret;
                ++left;
            }
        }
        
        return ret;
    }
}

public class Solution{
    public static void main(String[] args) throws IOE Exception{
        //The input output code have been provided for you on the website.
    }
}