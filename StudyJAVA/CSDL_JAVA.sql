USE [master]
GO
/****** Object:  Database [CSDL_JAVA]    Script Date: 4/17/2023 11:40:50 PM ******/
CREATE DATABASE [CSDL_JAVA]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'CSDL_JAVA', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\DATA\CSDL_JAVA.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'CSDL_JAVA_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\DATA\CSDL_JAVA_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT, LEDGER = OFF
GO
ALTER DATABASE [CSDL_JAVA] SET COMPATIBILITY_LEVEL = 160
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [CSDL_JAVA].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [CSDL_JAVA] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET ARITHABORT OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [CSDL_JAVA] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [CSDL_JAVA] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET  DISABLE_BROKER 
GO
ALTER DATABASE [CSDL_JAVA] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [CSDL_JAVA] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [CSDL_JAVA] SET  MULTI_USER 
GO
ALTER DATABASE [CSDL_JAVA] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [CSDL_JAVA] SET DB_CHAINING OFF 
GO
ALTER DATABASE [CSDL_JAVA] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [CSDL_JAVA] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [CSDL_JAVA] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [CSDL_JAVA] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [CSDL_JAVA] SET QUERY_STORE = ON
GO
ALTER DATABASE [CSDL_JAVA] SET QUERY_STORE (OPERATION_MODE = READ_WRITE, CLEANUP_POLICY = (STALE_QUERY_THRESHOLD_DAYS = 30), DATA_FLUSH_INTERVAL_SECONDS = 900, INTERVAL_LENGTH_MINUTES = 60, MAX_STORAGE_SIZE_MB = 1000, QUERY_CAPTURE_MODE = AUTO, SIZE_BASED_CLEANUP_MODE = AUTO, MAX_PLANS_PER_QUERY = 200, WAIT_STATS_CAPTURE_MODE = ON)
GO
USE [CSDL_JAVA]
GO
/****** Object:  Table [dbo].[HOCVIEN]    Script Date: 4/17/2023 11:40:50 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HOCVIEN](
	[MaHocVien] [nvarchar](10) NOT NULL,
	[TenHocVien] [nvarchar](50) NULL,
	[Ngáyinh] [datetime] NULL,
	[GioiTinh] [nvarchar](3) NULL,
	[DiemThi] [float] NULL
) ON [PRIMARY]
GO
USE [master]
GO
ALTER DATABASE [CSDL_JAVA] SET  READ_WRITE 
GO
