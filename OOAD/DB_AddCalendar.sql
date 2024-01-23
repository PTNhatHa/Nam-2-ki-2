USE [master]
GO
/****** Object:  Database [OOAD]    Script Date: 4/11/2023 9:48:56 PM ******/
CREATE DATABASE [OOAD]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'OOAD', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\DATA\OOAD.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'OOAD_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\DATA\OOAD_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT, LEDGER = OFF
GO
ALTER DATABASE [OOAD] SET COMPATIBILITY_LEVEL = 160
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [OOAD].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [OOAD] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [OOAD] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [OOAD] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [OOAD] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [OOAD] SET ARITHABORT OFF 
GO
ALTER DATABASE [OOAD] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [OOAD] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [OOAD] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [OOAD] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [OOAD] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [OOAD] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [OOAD] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [OOAD] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [OOAD] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [OOAD] SET  DISABLE_BROKER 
GO
ALTER DATABASE [OOAD] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [OOAD] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [OOAD] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [OOAD] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [OOAD] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [OOAD] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [OOAD] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [OOAD] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [OOAD] SET  MULTI_USER 
GO
ALTER DATABASE [OOAD] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [OOAD] SET DB_CHAINING OFF 
GO
ALTER DATABASE [OOAD] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [OOAD] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [OOAD] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [OOAD] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [OOAD] SET QUERY_STORE = ON
GO
ALTER DATABASE [OOAD] SET QUERY_STORE (OPERATION_MODE = READ_WRITE, CLEANUP_POLICY = (STALE_QUERY_THRESHOLD_DAYS = 30), DATA_FLUSH_INTERVAL_SECONDS = 900, INTERVAL_LENGTH_MINUTES = 60, MAX_STORAGE_SIZE_MB = 1000, QUERY_CAPTURE_MODE = AUTO, SIZE_BASED_CLEANUP_MODE = AUTO, MAX_PLANS_PER_QUERY = 200, WAIT_STATS_CAPTURE_MODE = ON)
GO
USE [OOAD]
GO
/****** Object:  Table [dbo].[Appointment]    Script Date: 4/11/2023 9:48:56 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Appointment](
	[ID] [int] NOT NULL,
	[Name] [varchar](50) NULL,
	[Location] [varchar](50) NULL,
	[Date] [date] NULL,
	[Begin_Time] [time](7) NULL,
	[End_Time] [time](7) NULL,
	[GroupMeeting] [bit] NULL,
 CONSTRAINT [PK_Appointments] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Participant]    Script Date: 4/11/2023 9:48:56 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Participant](
	[ID_Guest] [int] NOT NULL,
	[ID_Appointment] [int] NOT NULL,
	[Guest] [nvarchar](50) NULL,
 CONSTRAINT [PK_GroupMeeting] PRIMARY KEY CLUSTERED 
(
	[ID_Guest] ASC,
	[ID_Appointment] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Reminder]    Script Date: 4/11/2023 9:48:56 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Reminder](
	[ID_Appointment] [int] NOT NULL,
	[TimeReminder] [datetime] NULL,
	[Reminder] [nvarchar](50) NULL,
 CONSTRAINT [PK_Reminders_1] PRIMARY KEY CLUSTERED 
(
	[ID_Appointment] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (1, N'Do1', N'Location1', CAST(N'2023-04-04' AS Date), CAST(N'06:00:00' AS Time), CAST(N'09:00:00' AS Time), 1)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (2, N'Do2', N'lo3', CAST(N'2023-04-05' AS Date), CAST(N'09:00:00' AS Time), CAST(N'12:00:00' AS Time), 1)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (3, N'Do3', N'Location3', CAST(N'2023-04-06' AS Date), CAST(N'06:00:00' AS Time), CAST(N'12:00:00' AS Time), 1)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (4, N'Do4', N'Location1', CAST(N'2023-04-06' AS Date), CAST(N'15:00:00' AS Time), CAST(N'19:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (5, N'Do5', N'Location3', CAST(N'2023-04-07' AS Date), CAST(N'06:00:00' AS Time), CAST(N'12:00:00' AS Time), 1)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (6, N'Do6', N'adc', CAST(N'2023-04-11' AS Date), CAST(N'06:00:00' AS Time), CAST(N'09:00:00' AS Time), 1)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (7, N'Do7', N'loca1', CAST(N'2023-04-20' AS Date), CAST(N'06:00:00' AS Time), CAST(N'09:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (8, N'Do8', N'loca6', CAST(N'2023-04-04' AS Date), CAST(N'06:00:00' AS Time), CAST(N'09:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (9, N'Do9', N'loc1', CAST(N'2023-04-05' AS Date), CAST(N'06:00:00' AS Time), CAST(N'09:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (10, N'do10', N'lo9', CAST(N'2023-04-05' AS Date), CAST(N'06:00:00' AS Time), CAST(N'09:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (11, N'do11', N'lo1', CAST(N'2023-04-05' AS Date), CAST(N'06:00:00' AS Time), CAST(N'09:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (12, N'do12', N'lo2', CAST(N'2023-04-11' AS Date), CAST(N'06:00:00' AS Time), CAST(N'08:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (13, N'do13', N'lo5', CAST(N'2023-04-11' AS Date), CAST(N'10:00:00' AS Time), CAST(N'12:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (14, N'do14', N'lo5', CAST(N'2023-04-11' AS Date), CAST(N'10:00:00' AS Time), CAST(N'15:00:00' AS Time), 1)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (19, N'Do17', N'lo1', CAST(N'2023-04-11' AS Date), CAST(N'06:00:00' AS Time), CAST(N'09:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (20, N'Do23', N'Lo23', CAST(N'2023-04-11' AS Date), CAST(N'15:00:00' AS Time), CAST(N'19:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (21, N'Do21', N'lo9', CAST(N'2023-04-12' AS Date), CAST(N'07:00:00' AS Time), CAST(N'09:00:00' AS Time), 0)
INSERT [dbo].[Appointment] ([ID], [Name], [Location], [Date], [Begin_Time], [End_Time], [GroupMeeting]) VALUES (22, N'Do22', N'lo22', CAST(N'2023-04-12' AS Date), CAST(N'10:00:00' AS Time), CAST(N'12:00:00' AS Time), 0)
GO
INSERT [dbo].[Participant] ([ID_Guest], [ID_Appointment], [Guest]) VALUES (1, 1, N'Hạ')
INSERT [dbo].[Participant] ([ID_Guest], [ID_Appointment], [Guest]) VALUES (1, 2, N'Hạ')
INSERT [dbo].[Participant] ([ID_Guest], [ID_Appointment], [Guest]) VALUES (1, 3, N'Hạ')
INSERT [dbo].[Participant] ([ID_Guest], [ID_Appointment], [Guest]) VALUES (1, 6, N'Hạ')
INSERT [dbo].[Participant] ([ID_Guest], [ID_Appointment], [Guest]) VALUES (2, 1, N'Hy')
INSERT [dbo].[Participant] ([ID_Guest], [ID_Appointment], [Guest]) VALUES (3, 1, N'Quìn')
INSERT [dbo].[Participant] ([ID_Guest], [ID_Appointment], [Guest]) VALUES (3, 2, N'Quìn')
INSERT [dbo].[Participant] ([ID_Guest], [ID_Appointment], [Guest]) VALUES (4, 2, N'Thảo')
GO
INSERT [dbo].[Reminder] ([ID_Appointment], [TimeReminder], [Reminder]) VALUES (1, CAST(N'2023-04-04T05:00:00.000' AS DateTime), N'Nhắc 1')
INSERT [dbo].[Reminder] ([ID_Appointment], [TimeReminder], [Reminder]) VALUES (3, CAST(N'2023-04-06T05:00:00.000' AS DateTime), N'Nhắc 3')
INSERT [dbo].[Reminder] ([ID_Appointment], [TimeReminder], [Reminder]) VALUES (14, CAST(N'2023-04-11T09:00:00.000' AS DateTime), N'Lời nhắc do13')
INSERT [dbo].[Reminder] ([ID_Appointment], [TimeReminder], [Reminder]) VALUES (22, CAST(N'2023-04-12T09:00:00.000' AS DateTime), N'Remind me')
GO
ALTER TABLE [dbo].[Participant]  WITH CHECK ADD  CONSTRAINT [FK_Participant_Appointment] FOREIGN KEY([ID_Appointment])
REFERENCES [dbo].[Appointment] ([ID])
GO
ALTER TABLE [dbo].[Participant] CHECK CONSTRAINT [FK_Participant_Appointment]
GO
ALTER TABLE [dbo].[Reminder]  WITH CHECK ADD  CONSTRAINT [FK_Reminder_Appointment] FOREIGN KEY([ID_Appointment])
REFERENCES [dbo].[Appointment] ([ID])
GO
ALTER TABLE [dbo].[Reminder] CHECK CONSTRAINT [FK_Reminder_Appointment]
GO
USE [master]
GO
ALTER DATABASE [OOAD] SET  READ_WRITE 
GO
