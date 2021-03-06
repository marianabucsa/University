USE [Inchirieri_auto]
GO
/****** Object:  Table [dbo].[Angajati]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Angajati](
	[id_angajat] [int] NOT NULL,
	[nume_angajat] [nvarchar](30) NOT NULL,
	[prenume_angajat] [nvarchar](60) NOT NULL,
	[salariu] [float] NOT NULL,
	[pozitia_curenta] [nvarchar](50) NULL,
	[id_locatie] [int] NULL,
	[procentaj] [float] NULL,
 CONSTRAINT [PK_Angajati] PRIMARY KEY CLUSTERED 
(
	[id_angajat] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Angajati_Verificari]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Angajati_Verificari](
	[id_angajat] [int] NOT NULL,
	[id_verificare] [int] NOT NULL,
	[procentaj] [float] NULL,
 CONSTRAINT [PK_Angajati_Verificari] PRIMARY KEY CLUSTERED 
(
	[id_angajat] ASC,
	[id_verificare] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Asigurari]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Asigurari](
	[id_asigurare] [int] NOT NULL,
	[id_masina] [int] NULL,
	[tip_asigurare] [nvarchar](30) NULL,
	[descriere] [nvarchar](1000) NULL,
	[data_inceperii] [date] NULL,
	[data_expirarii] [date] NULL,
 CONSTRAINT [PK_Asigurari] PRIMARY KEY CLUSTERED 
(
	[id_asigurare] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Clienti]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Clienti](
	[id_client] [int] NOT NULL,
	[nume_client] [nvarchar](30) NOT NULL,
	[prenume_client] [nvarchar](60) NOT NULL,
	[adresa_client] [nvarchar](300) NULL,
	[telefon_client] [char](10) NULL,
 CONSTRAINT [PK_Clienti] PRIMARY KEY CLUSTERED 
(
	[id_client] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Inchirieri]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Inchirieri](
	[id_inchiriere] [int] NOT NULL,
	[id_masina] [int] NOT NULL,
	[id_client] [int] NOT NULL,
	[id_angajat] [int] NOT NULL,
	[plata] [money] NULL,
	[data_inchiriere] [date] NULL,
	[data_retur] [date] NULL,
	[status_inchiriere] [nvarchar](50) NULL,
 CONSTRAINT [PK_Inchirieri] PRIMARY KEY CLUSTERED 
(
	[id_inchiriere] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Locatii]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Locatii](
	[id_locatie] [int] NOT NULL,
	[oras] [nvarchar](100) NULL,
	[nume_strada] [nvarchar](200) NULL,
	[nr_strada] [float] NULL,
	[cod_postal] [nvarchar](10) NULL,
	[id_manager] [int] NULL,
 CONSTRAINT [PK_Magazine] PRIMARY KEY CLUSTERED 
(
	[id_locatie] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Manageri]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Manageri](
	[id_manager] [int] NOT NULL,
	[nume] [nvarchar](50) NULL,
	[prenume] [nvarchar](50) NULL,
 CONSTRAINT [PK_Manageri] PRIMARY KEY CLUSTERED 
(
	[id_manager] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Masini]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Masini](
	[id_masina] [int] NOT NULL,
	[id_locatie] [int] NULL,
	[id_model] [int] NULL,
	[an_fabricare] [smallint] NULL,
	[culoare_masina] [nvarchar](20) NULL,
	[capacitate_masina] [tinyint] NULL,
 CONSTRAINT [PK_Masini] PRIMARY KEY CLUSTERED 
(
	[id_masina] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Modele]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Modele](
	[id_model] [int] NOT NULL,
	[denumire_model] [nvarchar](50) NULL,
	[denumire_producator] [nvarchar](50) NULL,
 CONSTRAINT [PK_Modele] PRIMARY KEY CLUSTERED 
(
	[id_model] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tables]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tables](
	[TableID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Tables] PRIMARY KEY CLUSTERED 
(
	[TableID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestRuns]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestRuns](
	[TestRunID] [int] IDENTITY(1,1) NOT NULL,
	[Description] [nvarchar](2000) NULL,
	[StartAt] [datetime] NULL,
	[EndAt] [datetime] NULL,
 CONSTRAINT [PK_TestRuns] PRIMARY KEY CLUSTERED 
(
	[TestRunID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestRunTables]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestRunTables](
	[TestRunID] [int] NOT NULL,
	[TableID] [int] NOT NULL,
	[StartAt] [datetime] NOT NULL,
	[EndAt] [datetime] NOT NULL,
 CONSTRAINT [PK_TestRunTables] PRIMARY KEY CLUSTERED 
(
	[TestRunID] ASC,
	[TableID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestRunViews]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestRunViews](
	[TestRunID] [int] NOT NULL,
	[ViewID] [int] NOT NULL,
	[StartAt] [datetime] NOT NULL,
	[EndAt] [datetime] NOT NULL,
 CONSTRAINT [PK_TestRunViews] PRIMARY KEY CLUSTERED 
(
	[TestRunID] ASC,
	[ViewID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tests]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tests](
	[TestID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Tests] PRIMARY KEY CLUSTERED 
(
	[TestID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestTables]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestTables](
	[TestID] [int] NOT NULL,
	[TableID] [int] NOT NULL,
	[NoOfRows] [int] NOT NULL,
	[Position] [int] NOT NULL,
 CONSTRAINT [PK_TestTables] PRIMARY KEY CLUSTERED 
(
	[TestID] ASC,
	[TableID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestViews]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestViews](
	[TestID] [int] NOT NULL,
	[ViewID] [int] NOT NULL,
 CONSTRAINT [PK_TestViews] PRIMARY KEY CLUSTERED 
(
	[TestID] ASC,
	[ViewID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Verificari]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Verificari](
	[id_verificare] [int] NOT NULL,
	[data_verificare] [datetime] NULL,
	[rezultat_verificare] [nvarchar](1000) NULL,
	[id_masina] [int] NULL,
 CONSTRAINT [PK_Verificari] PRIMARY KEY CLUSTERED 
(
	[id_verificare] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Versiune]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Versiune](
	[NrVersiune] [int] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Views]    Script Date: 12/04/2022 10:38:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Views](
	[ViewID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Views] PRIMARY KEY CLUSTERED 
(
	[ViewID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[Angajati] ADD  CONSTRAINT [DF_Angajati_procentaj]  DEFAULT ((0)) FOR [procentaj]
GO
ALTER TABLE [dbo].[Angajati]  WITH CHECK ADD  CONSTRAINT [FK_Angajati_Magazine] FOREIGN KEY([id_locatie])
REFERENCES [dbo].[Locatii] ([id_locatie])
GO
ALTER TABLE [dbo].[Angajati] CHECK CONSTRAINT [FK_Angajati_Magazine]
GO
ALTER TABLE [dbo].[Angajati_Verificari]  WITH CHECK ADD  CONSTRAINT [FK_Angajati_Verificari_Angajati] FOREIGN KEY([id_angajat])
REFERENCES [dbo].[Angajati] ([id_angajat])
GO
ALTER TABLE [dbo].[Angajati_Verificari] CHECK CONSTRAINT [FK_Angajati_Verificari_Angajati]
GO
ALTER TABLE [dbo].[Angajati_Verificari]  WITH CHECK ADD  CONSTRAINT [FK_Angajati_Verificari_Verificari] FOREIGN KEY([id_verificare])
REFERENCES [dbo].[Verificari] ([id_verificare])
GO
ALTER TABLE [dbo].[Angajati_Verificari] CHECK CONSTRAINT [FK_Angajati_Verificari_Verificari]
GO
ALTER TABLE [dbo].[Asigurari]  WITH CHECK ADD  CONSTRAINT [FK_Asigurari_Masini] FOREIGN KEY([id_masina])
REFERENCES [dbo].[Masini] ([id_masina])
GO
ALTER TABLE [dbo].[Asigurari] CHECK CONSTRAINT [FK_Asigurari_Masini]
GO
ALTER TABLE [dbo].[Inchirieri]  WITH CHECK ADD  CONSTRAINT [FK_Inchirieri_Angajati] FOREIGN KEY([id_angajat])
REFERENCES [dbo].[Angajati] ([id_angajat])
GO
ALTER TABLE [dbo].[Inchirieri] CHECK CONSTRAINT [FK_Inchirieri_Angajati]
GO
ALTER TABLE [dbo].[Inchirieri]  WITH CHECK ADD  CONSTRAINT [FK_Inchirieri_Clienti] FOREIGN KEY([id_client])
REFERENCES [dbo].[Clienti] ([id_client])
GO
ALTER TABLE [dbo].[Inchirieri] CHECK CONSTRAINT [FK_Inchirieri_Clienti]
GO
ALTER TABLE [dbo].[Inchirieri]  WITH CHECK ADD  CONSTRAINT [FK_Inchirieri_Masini] FOREIGN KEY([id_masina])
REFERENCES [dbo].[Masini] ([id_masina])
GO
ALTER TABLE [dbo].[Inchirieri] CHECK CONSTRAINT [FK_Inchirieri_Masini]
GO
ALTER TABLE [dbo].[Locatii]  WITH CHECK ADD  CONSTRAINT [FK_Locatii_Manageri] FOREIGN KEY([id_manager])
REFERENCES [dbo].[Manageri] ([id_manager])
GO
ALTER TABLE [dbo].[Locatii] CHECK CONSTRAINT [FK_Locatii_Manageri]
GO
ALTER TABLE [dbo].[Masini]  WITH CHECK ADD  CONSTRAINT [FK_Masini_Locatii] FOREIGN KEY([id_locatie])
REFERENCES [dbo].[Locatii] ([id_locatie])
GO
ALTER TABLE [dbo].[Masini] CHECK CONSTRAINT [FK_Masini_Locatii]
GO
ALTER TABLE [dbo].[Masini]  WITH CHECK ADD  CONSTRAINT [FK_Masini_Modele] FOREIGN KEY([id_model])
REFERENCES [dbo].[Modele] ([id_model])
GO
ALTER TABLE [dbo].[Masini] CHECK CONSTRAINT [FK_Masini_Modele]
GO
ALTER TABLE [dbo].[TestRunTables]  WITH CHECK ADD  CONSTRAINT [FK_TestRunTables_Tables] FOREIGN KEY([TableID])
REFERENCES [dbo].[Tables] ([TableID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestRunTables] CHECK CONSTRAINT [FK_TestRunTables_Tables]
GO
ALTER TABLE [dbo].[TestRunTables]  WITH CHECK ADD  CONSTRAINT [FK_TestRunTables_TestRuns] FOREIGN KEY([TestRunID])
REFERENCES [dbo].[TestRuns] ([TestRunID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestRunTables] CHECK CONSTRAINT [FK_TestRunTables_TestRuns]
GO
ALTER TABLE [dbo].[TestRunViews]  WITH CHECK ADD  CONSTRAINT [FK_TestRunViews_TestRuns] FOREIGN KEY([TestRunID])
REFERENCES [dbo].[TestRuns] ([TestRunID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestRunViews] CHECK CONSTRAINT [FK_TestRunViews_TestRuns]
GO
ALTER TABLE [dbo].[TestRunViews]  WITH CHECK ADD  CONSTRAINT [FK_TestRunViews_Views] FOREIGN KEY([ViewID])
REFERENCES [dbo].[Views] ([ViewID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestRunViews] CHECK CONSTRAINT [FK_TestRunViews_Views]
GO
ALTER TABLE [dbo].[TestTables]  WITH CHECK ADD  CONSTRAINT [FK_TestTables_Tables] FOREIGN KEY([TableID])
REFERENCES [dbo].[Tables] ([TableID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestTables] CHECK CONSTRAINT [FK_TestTables_Tables]
GO
ALTER TABLE [dbo].[TestTables]  WITH CHECK ADD  CONSTRAINT [FK_TestTables_Tests] FOREIGN KEY([TestID])
REFERENCES [dbo].[Tests] ([TestID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestTables] CHECK CONSTRAINT [FK_TestTables_Tests]
GO
ALTER TABLE [dbo].[TestViews]  WITH CHECK ADD  CONSTRAINT [FK_TestViews_Tests] FOREIGN KEY([TestID])
REFERENCES [dbo].[Tests] ([TestID])
GO
ALTER TABLE [dbo].[TestViews] CHECK CONSTRAINT [FK_TestViews_Tests]
GO
ALTER TABLE [dbo].[TestViews]  WITH CHECK ADD  CONSTRAINT [FK_TestViews_Views] FOREIGN KEY([ViewID])
REFERENCES [dbo].[Views] ([ViewID])
GO
ALTER TABLE [dbo].[TestViews] CHECK CONSTRAINT [FK_TestViews_Views]
GO
