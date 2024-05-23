import java.io.DataInputStream;
import listas.*;

class Principal{

	public static void main(String[] args) {
		
		Lista ml = new Lista(); // ml: minhalista
		char o,e; // o:opcao e:temporario

		DataInputStream 	meuDataInputStream = new DataInputStream(System.in);

		try {
			do {
				o = (char) meuDataInputStream.read();
				switch (o){
					case 'i':
						e = (char) meuDataInputStream.read();
						ml.insere(e);
						break;
					case 'r':
						e = ml.remove();
						System.out.println(e);
						//System.out.flush
						break;
					case 'm':
						ml.mostra();
						System.out.println();
						//System.out.flush
						break;
					default:;
				}
			} while(o != 'q');
		}
		catch (Exception erro) { /* Do nothing */ }
	}
}