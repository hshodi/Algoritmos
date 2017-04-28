package ado666;

import java.util.HashSet;

import java.util.Iterator;

import java.util.LinkedHashSet;

import java.util.LinkedHashSet;



public class Ado666 {



    public static void main(String[] args) {

        

        HashSet<Integer> itens = new HashSet<Integer>();

        LinkedHashSet<Integer> itensrash = new LinkedHashSet<Integer>();

        

        int x=0;

        

        //add no comum

        for(int i=0;i<25;i++)

        {

            itens.add(x+=3);

        }

        

        x=1;

        

        //add no linked

        for(int i=0;i<25;i++)

        {

            itensrash.add(x++);

        }



        //iterators

        Iterator<Integer> um = itens.iterator();

        Iterator<Integer> dois = itensrash.iterator();



        

        System.out.printf("Hash comum\n");

        while (um.hasNext()) 

        {

            System.out.printf("%d ",um.next());;

        }

        

        //

        System.out.printf("\n");

        //

        

        System.out.printf("Linked\n");

        while (dois.hasNext()) 

        {

            System.out.printf("%d ",dois.next());;

        }

        

        //

        System.out.printf("\n");

        //

    }

    

}
