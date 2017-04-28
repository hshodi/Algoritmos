import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Iterator;

public class TesteHash{

	public static void main(String[] args){
		HashSet<Integer> itens = new HashSet<Integer>();
		LinkedHashSet<Integer> itensLinked = new LinkedHashSet<Integer>();
		
		int val = 0;
		int k;
		int aux = 0;
		for(k = 1; k < 25; k++){
			itens.add(val + 3);
			val++;
		}
		int w = 0;
		for(aux = 1; aux < 25; aux++){
			itensLinked.add(w + 3);
			w++;
		}

		Iterator<Integer> primeiro = itens.iterator();
		Iterator<Integer> segundo = itensLinked.iterator();

		System.out.printf("HASHSET -----------\n");
		while( primeiro.hasNext() ){
			System.out.printf("%d ", primeiro.next() );
		}
		System.out.printf("\nLinkedHashSet ------------\n");
		while( segundo.hasNext() ){
			System.out.printf("%d ", segundo.next());
		}
	}

}
