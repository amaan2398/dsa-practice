/*
@ Creator: Amaan Shaikh
@ Problem_Title: IntroToDQ
    @ Problem_Statement: 
    @ Data_Structure: 
    @ Algorithm:
    @ Level: 
    @ URL: 
@ Approach: Introduction to Deque
@ Date_Time: August 19, 2022 14:14:42
*/

// import java.util.*;
import java.util.ArrayDeque;
import java.util.Iterator;
import java.util.TreeSet;

class Code{
    public static void main(String[] args){
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.offerFirst(1);
        dq.offerFirst(2);
        dq.offerFirst(3);
        dq.offerFirst(4);
        dq.offerFirst(5);

        dq.offerLast(6);
        dq.offerLast(7);
        dq.offerLast(8);
        dq.offerLast(9);
        System.out.println(dq);

        System.out.println(dq.pollFirst());
        System.out.println(dq.pollLast());
        System.out.println(dq.peek());
        System.out.println(dq.peekLast());
        System.out.println(dq);
        Iterator<Integer> it = dq.iterator();
        for(Integer ele : dq){
            System.out.print(ele+" _ ");
        }
        System.out.println();
        while(it.hasNext()){
            System.out.println(it.next());
        }
        

    } 
}