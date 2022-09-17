import java.util.ArrayList;

import javax.accessibility.AccessibleRelation;

import java.util.*;
public class ActivitySelection {

    public static void main(String args[]) {
        
        int start[]={1,3,0,5,8,5};
        int end[]={2,4,6,7,9,9};

     //   ArrayList<Integer> list=new ArrayList<>();
        int activities[][]=new int[start.length][3];

        for(int i=0;i<start.length;i++){
            activities[i][0]=i;
            activities[i][1]=start[i];
            activities[i][2]=end[i];
        }
        
        Arrays.sort(activities,Comparator.comparingDouble(o -> o[2]));


        int maxEnd=activities[0][2];
        int count=1;

     //   list.add(0);
        for(int i=1;i<end.length;i++){

            if(activities[i][1]>=maxEnd){
                count++;
               // list.add(i);
                maxEnd=activities[i][2];
            }
        }


        // for (int i = 0; i < list.size(); i++) {
            
        //     System.out.print(list.get(i)+" ");
        // }
        // System.out.println();
        System.out.println(count);
    }
    
}
