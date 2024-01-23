package IO_STREAM;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;

public class DocGhiDL {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		//ĐỌC DL TỪ FILE
		File fileInput = new File("D:\\LEARNING\\HK4\\JAVA\\input.txt.txt");
		InputStream inputStream = new FileInputStream(fileInput);
		InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
		BufferedReader reader = new BufferedReader(inputStreamReader);
		String line = "";
//        while((line = reader.readLine()) != null)
//        {
//            System.out.println(line);
//        }
        
        //GHI DL RA FILE
        File fileOutput = new File("D:\\LEARNING\\HK4\\JAVA\\output.txt.txt");
        OutputStream outputStream = new FileOutputStream(fileOutput);
        OutputStreamWriter outputStreamWriter = new OutputStreamWriter(outputStream);
        
        while((line = reader.readLine()) != null)
        {
            System.out.println(line);
            outputStreamWriter.write(line);
            outputStreamWriter.write("\n");
        }
        outputStreamWriter.flush();
        // Đây là phương thức quan trọng!
        // Nó sẽ bắt chương trình chờ ghi dữ liệu xong thì mới kết thúc chương trình.
        
	}

}
