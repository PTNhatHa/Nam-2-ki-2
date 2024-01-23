package IO_STREAM;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;

public class DocFileByReader {
	public static void main(String[] args) throws Exception {
		FileReader fr = new FileReader(new File("D:\\LEARNING\\HK4\\JAVA\\test.txt"));
		BufferedReader br = new BufferedReader(fr);
		String s = br.readLine();
		
		FileWriter fu = new FileWriter("D:\\LEARNING\\HK4\\JAVA\\output.txt");
		BufferedWriter bw = new BufferedWriter(fu);
		
		bw.write(s);
		System.out.println(s);
		br.close();
		bw.close();
	}
}
