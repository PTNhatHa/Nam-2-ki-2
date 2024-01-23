USE [QLSV_final]
GO
/****** Object:  Table [dbo].[Information]    Script Date: 3/23/2023 7:49:53 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Information](
	[MSSV] [varchar](3) NOT NULL,
	[HoTen] [nvarchar](50) NULL,
	[LSH] [nchar](10) NULL,
	[NgaySinh] [date] NULL,
	[DTB] [float] NULL,
	[GioiTinh] [bit] NULL,
	[Anh] [bit] NULL,
	[HB] [bit] NULL,
	[CCCD] [bit] NULL
) ON [PRIMARY]
GO
INSERT [dbo].[Information] ([MSSV], [HoTen], [LSH], [NgaySinh], [DTB], [GioiTinh], [Anh], [HB], [CCCD]) VALUES (N'100', N'NVC', N'21DT2     ', CAST(N'2023-03-23' AS Date), 8, 0, 1, 0, 0)
INSERT [dbo].[Information] ([MSSV], [HoTen], [LSH], [NgaySinh], [DTB], [GioiTinh], [Anh], [HB], [CCCD]) VALUES (N'400', N'NVD', N'21DT3     ', CAST(N'2003-01-05' AS Date), 4.4, 0, 1, 1, 0)
INSERT [dbo].[Information] ([MSSV], [HoTen], [LSH], [NgaySinh], [DTB], [GioiTinh], [Anh], [HB], [CCCD]) VALUES (N'500', N'NVE', N'21DT3     ', CAST(N'2003-09-10' AS Date), 5.5, 1, 0, 0, 1)
INSERT [dbo].[Information] ([MSSV], [HoTen], [LSH], [NgaySinh], [DTB], [GioiTinh], [Anh], [HB], [CCCD]) VALUES (N'200', N'NVB', N'21DT1     ', CAST(N'2003-10-15' AS Date), 2.2, 1, 0, 1, 0)
INSERT [dbo].[Information] ([MSSV], [HoTen], [LSH], [NgaySinh], [DTB], [GioiTinh], [Anh], [HB], [CCCD]) VALUES (N'300', N'NVA', N'21DT4     ', CAST(N'2023-03-23' AS Date), 3.1, 0, 1, 0, 0)
INSERT [dbo].[Information] ([MSSV], [HoTen], [LSH], [NgaySinh], [DTB], [GioiTinh], [Anh], [HB], [CCCD]) VALUES (N'600', N'NVG', N'21DT3     ', CAST(N'2023-03-23' AS Date), 6, 1, 0, 1, 1)
INSERT [dbo].[Information] ([MSSV], [HoTen], [LSH], [NgaySinh], [DTB], [GioiTinh], [Anh], [HB], [CCCD]) VALUES (N'700', N'NVH', N'21DT5     ', CAST(N'2023-03-23' AS Date), 7, 0, 1, 0, 1)
INSERT [dbo].[Information] ([MSSV], [HoTen], [LSH], [NgaySinh], [DTB], [GioiTinh], [Anh], [HB], [CCCD]) VALUES (N'800', N'NVK', N'21DT2     ', CAST(N'2023-03-23' AS Date), 9, 1, 1, 0, 0)
INSERT [dbo].[Information] ([MSSV], [HoTen], [LSH], [NgaySinh], [DTB], [GioiTinh], [Anh], [HB], [CCCD]) VALUES (N'900', N'NVQ', N'21DT2     ', CAST(N'2023-03-23' AS Date), 2, 0, 1, 0, 0)
GO
