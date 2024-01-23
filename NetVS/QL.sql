USE [QLDT]
GO
/****** Object:  Table [dbo].[Giảng_Viên]    Script Date: 3/26/2023 10:57:58 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Giảng_Viên](
	[Mã giảng viên] [varchar](10) NOT NULL,
	[Tên giảng viên] [nvarchar](50) NULL,
	[Ngày sinh] [date] NULL,
	[Khoa] [nvarchar](50) NULL,
	[Học hàm] [nvarchar](50) NULL,
	[Học vị] [nvarchar](50) NULL,
	[Giới tính] [bit] NULL,
 CONSTRAINT [PK_Giảng_Viên] PRIMARY KEY CLUSTERED 
(
	[Mã giảng viên] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[GV_HP]    Script Date: 3/26/2023 10:57:58 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GV_HP](
	[Mã giảng viên] [varchar](10) NOT NULL,
	[Mã học phần] [varchar](10) NOT NULL,
 CONSTRAINT [PK_GV_HP] PRIMARY KEY CLUSTERED 
(
	[Mã giảng viên] ASC,
	[Mã học phần] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Học_phần]    Script Date: 3/26/2023 10:57:58 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Học_phần](
	[Mã học phần] [varchar](10) NOT NULL,
	[Tên học phần] [nvarchar](50) NULL,
 CONSTRAINT [PK_Học_phần] PRIMARY KEY CLUSTERED 
(
	[Mã học phần] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[Giảng_Viên] ([Mã giảng viên], [Tên giảng viên], [Ngày sinh], [Khoa], [Học hàm], [Học vị], [Giới tính]) VALUES (N'1000', N'Nguyễn Văn A', CAST(N'1989-01-02' AS Date), N'Công nghệ thông tin', N'Giáo sư', N'Thạc Sỹ', 1)
INSERT [dbo].[Giảng_Viên] ([Mã giảng viên], [Tên giảng viên], [Ngày sinh], [Khoa], [Học hàm], [Học vị], [Giới tính]) VALUES (N'1001', N'Phạm Trần Văn C', CAST(N'1987-05-06' AS Date), N'Đại cương', N'Không', N'Tiến Sỹ', 1)
INSERT [dbo].[Giảng_Viên] ([Mã giảng viên], [Tên giảng viên], [Ngày sinh], [Khoa], [Học hàm], [Học vị], [Giới tính]) VALUES (N'1002', N'Nguyễn Đức D', CAST(N'1990-09-01' AS Date), N'Toán', N'Giáo sư', N'Tiến sỹ khoa học', 1)
INSERT [dbo].[Giảng_Viên] ([Mã giảng viên], [Tên giảng viên], [Ngày sinh], [Khoa], [Học hàm], [Học vị], [Giới tính]) VALUES (N'1003', N'NVB', CAST(N'1987-03-11' AS Date), N'Điện', N'Phó Giáo sư', N'Tiến Sỹ', 0)
INSERT [dbo].[Giảng_Viên] ([Mã giảng viên], [Tên giảng viên], [Ngày sinh], [Khoa], [Học hàm], [Học vị], [Giới tính]) VALUES (N'1004', N'Trần Thị B', CAST(N'1969-04-05' AS Date), N'Công nghệ thông tin', N'Phó Giáo sư', N'Tiến Sỹ', 0)
INSERT [dbo].[Giảng_Viên] ([Mã giảng viên], [Tên giảng viên], [Ngày sinh], [Khoa], [Học hàm], [Học vị], [Giới tính]) VALUES (N'1005', N'Trần Hồng E', CAST(N'1990-02-08' AS Date), N'Toán', N'Không', N'Thạc Sỹ', 0)
GO
INSERT [dbo].[GV_HP] ([Mã giảng viên], [Mã học phần]) VALUES (N'1000', N'102')
INSERT [dbo].[GV_HP] ([Mã giảng viên], [Mã học phần]) VALUES (N'1001', N'103')
INSERT [dbo].[GV_HP] ([Mã giảng viên], [Mã học phần]) VALUES (N'1002', N'104')
GO
INSERT [dbo].[Học_phần] ([Mã học phần], [Tên học phần]) VALUES (N'101', N'Lập trình Java')
INSERT [dbo].[Học_phần] ([Mã học phần], [Tên học phần]) VALUES (N'102', N'Mạng máy tính')
INSERT [dbo].[Học_phần] ([Mã học phần], [Tên học phần]) VALUES (N'103', N'Giải tích 1')
INSERT [dbo].[Học_phần] ([Mã học phần], [Tên học phần]) VALUES (N'104', N'Giải tích 2')
INSERT [dbo].[Học_phần] ([Mã học phần], [Tên học phần]) VALUES (N'105', N'Pháp luật đại cương')
GO
ALTER TABLE [dbo].[GV_HP]  WITH CHECK ADD  CONSTRAINT [FK_GV_HP_Giảng_Viên] FOREIGN KEY([Mã giảng viên])
REFERENCES [dbo].[Giảng_Viên] ([Mã giảng viên])
GO
ALTER TABLE [dbo].[GV_HP] CHECK CONSTRAINT [FK_GV_HP_Giảng_Viên]
GO
ALTER TABLE [dbo].[GV_HP]  WITH CHECK ADD  CONSTRAINT [FK_GV_HP_Học_phần] FOREIGN KEY([Mã học phần])
REFERENCES [dbo].[Học_phần] ([Mã học phần])
GO
ALTER TABLE [dbo].[GV_HP] CHECK CONSTRAINT [FK_GV_HP_Học_phần]
GO
