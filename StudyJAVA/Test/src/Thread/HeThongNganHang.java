//package Thread;
//
//public class HeThongNganHang {
//	int NganKho = 10000;
//
//	public HeThongNganHang() {
//		new ATM(this, "Hoa Khanh").start();
//		new ATM(this, "Hai Chau").start();
//	}
//
//	public static void main(String[] args) {
//		new HeThongNganHang();
//	}
//}
//
//class ATM extends Thread {
//	HeThongNganHang htnh;
//	String name;
//
//	public ATM(HeThongNganHang htnh, String name) {
//		this.htnh = htnh;
//		this.name = name;
//	}
//
//	void RutTien(String name, int i) {
//		synchronized (htnh) {
//			int tien = htnh.NganKho;
//			try {
//				Thread.sleep(1);
//			} catch (Exception e) {
//			}
//			tien = tien - 10;
//			htnh.NganKho = tien;
//			System.out.println(name + ": moi bi rut tien," + i + ", ngan kho con lai:" + htnh.NganKho);
//		}
//	}
//	public void run() {
//		for (int i = 0; i < 100; i++) {
//			RutTien(name, i);
//		}
//	}
//}