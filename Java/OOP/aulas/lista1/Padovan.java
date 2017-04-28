public class Padovan {

    public static int sequence(int val){
        switch(val){
            case 0:
                return 1;
            case 1:
                return 1;
            case 2:
                return 1;
            default:
                return sequence(val - 2) + sequence(val - 3);
        }
    }

    public static boolean prime(int val){

        if(val % 2 == 0 && val != 2 || val == 1) return false;
        for(int i = val - 1; i > 1; i--){
            if(val % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args){
        int curr = 0;
        int counter = 0;
        int result;
        for(int i = 0; counter < 5; i++){
            result = sequence(i);
            if(prime(result) && curr != result){
                System.out.println(result);
                curr = result;
                counter++;
            }
        }
    }   
}