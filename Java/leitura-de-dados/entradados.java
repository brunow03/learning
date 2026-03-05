import java.io.*;

class EntraDados{

	public static void main(String[] args) {
		byte vetortexto[] = new byte[200];
		int byteslidos = 0;

		System.out.println("Escreva algo:");

		try {
			byteslidos = System.in.read(vetortexto);
			System.out.println("Você escreveu:");
			System.out.write(vetortexto,0,byteslidos);
		}
		catch (IOException e) {
			System.out.println();
		}
	}
}