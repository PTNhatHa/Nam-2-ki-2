package IO_STREAM;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class DocFile {

	public static void main(String[] args) throws Exception {
		FileInputStream fis = new FileInputStream(new File ("D:\\LEARNING\\HK4\\JAVA\\input1.pdf"));
		BufferedInputStream bis = new BufferedInputStream(fis);
		
		FileOutputStream fos = new FileOutputStream(new File("D:\\LEARNING\\HK4\\JAVA\\output1.pdf"));
		BufferedOutputStream bos = new BufferedOutputStream(fos);
		
		int b;
		while ((b=fis.read())!=-1)
		{
			System.out.println(b);
			//bos.write(b);
		}
		fis.close();
		fos.close();
	}

}
