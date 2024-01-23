﻿#pragma warning disable 1591
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace QLSV
{
	using System.Data.Linq;
	using System.Data.Linq.Mapping;
	using System.Data;
	using System.Collections.Generic;
	using System.Reflection;
	using System.Linq;
	using System.Linq.Expressions;
	using System.ComponentModel;
	using System;
	
	
	[global::System.Data.Linq.Mapping.DatabaseAttribute(Name="NET1")]
	public partial class DB1DataContext : System.Data.Linq.DataContext
	{
		
		private static System.Data.Linq.Mapping.MappingSource mappingSource = new AttributeMappingSource();
		
    #region Extensibility Method Definitions
    partial void OnCreated();
    partial void InsertSV(SV instance);
    partial void UpdateSV(SV instance);
    partial void DeleteSV(SV instance);
    partial void InsertTenLop(TenLop instance);
    partial void UpdateTenLop(TenLop instance);
    partial void DeleteTenLop(TenLop instance);
    #endregion
		
		public DB1DataContext() : 
				base(global::QLSV.Properties.Settings.Default.NET1ConnectionString, mappingSource)
		{
			OnCreated();
		}
		
		public DB1DataContext(string connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public DB1DataContext(System.Data.IDbConnection connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public DB1DataContext(string connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public DB1DataContext(System.Data.IDbConnection connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public System.Data.Linq.Table<SV> SVs
		{
			get
			{
				return this.GetTable<SV>();
			}
		}
		
		public System.Data.Linq.Table<TenLop> TenLops
		{
			get
			{
				return this.GetTable<TenLop>();
			}
		}
	}
	
	[global::System.Data.Linq.Mapping.TableAttribute(Name="dbo.SV")]
	public partial class SV : INotifyPropertyChanging, INotifyPropertyChanged
	{
		
		private static PropertyChangingEventArgs emptyChangingEventArgs = new PropertyChangingEventArgs(String.Empty);
		
		private string _MaSV;
		
		private string _TenSV;
		
		private System.Nullable<bool> _Gender;
		
		private System.Nullable<double> _DTB;
		
		private int _IDLop;
		
		private EntityRef<TenLop> _TenLop;
		
    #region Extensibility Method Definitions
    partial void OnLoaded();
    partial void OnValidate(System.Data.Linq.ChangeAction action);
    partial void OnCreated();
    partial void OnMaSVChanging(string value);
    partial void OnMaSVChanged();
    partial void OnTenSVChanging(string value);
    partial void OnTenSVChanged();
    partial void OnGenderChanging(System.Nullable<bool> value);
    partial void OnGenderChanged();
    partial void OnDTBChanging(System.Nullable<double> value);
    partial void OnDTBChanged();
    partial void OnIDLopChanging(int value);
    partial void OnIDLopChanged();
    #endregion
		
		public SV()
		{
			this._TenLop = default(EntityRef<TenLop>);
			OnCreated();
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_MaSV", DbType="NVarChar(50) NOT NULL", CanBeNull=false, IsPrimaryKey=true)]
		public string MaSV
		{
			get
			{
				return this._MaSV;
			}
			set
			{
				if ((this._MaSV != value))
				{
					this.OnMaSVChanging(value);
					this.SendPropertyChanging();
					this._MaSV = value;
					this.SendPropertyChanged("MaSV");
					this.OnMaSVChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_TenSV", DbType="NVarChar(50)")]
		public string TenSV
		{
			get
			{
				return this._TenSV;
			}
			set
			{
				if ((this._TenSV != value))
				{
					this.OnTenSVChanging(value);
					this.SendPropertyChanging();
					this._TenSV = value;
					this.SendPropertyChanged("TenSV");
					this.OnTenSVChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Gender", DbType="Bit")]
		public System.Nullable<bool> Gender
		{
			get
			{
				return this._Gender;
			}
			set
			{
				if ((this._Gender != value))
				{
					this.OnGenderChanging(value);
					this.SendPropertyChanging();
					this._Gender = value;
					this.SendPropertyChanged("Gender");
					this.OnGenderChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_DTB", DbType="Float")]
		public System.Nullable<double> DTB
		{
			get
			{
				return this._DTB;
			}
			set
			{
				if ((this._DTB != value))
				{
					this.OnDTBChanging(value);
					this.SendPropertyChanging();
					this._DTB = value;
					this.SendPropertyChanged("DTB");
					this.OnDTBChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_IDLop", DbType="Int NOT NULL")]
		public int IDLop
		{
			get
			{
				return this._IDLop;
			}
			set
			{
				if ((this._IDLop != value))
				{
					if (this._TenLop.HasLoadedOrAssignedValue)
					{
						throw new System.Data.Linq.ForeignKeyReferenceAlreadyHasValueException();
					}
					this.OnIDLopChanging(value);
					this.SendPropertyChanging();
					this._IDLop = value;
					this.SendPropertyChanged("IDLop");
					this.OnIDLopChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.AssociationAttribute(Name="TenLop_SV", Storage="_TenLop", ThisKey="IDLop", OtherKey="IDLop", IsForeignKey=true)]
		public TenLop TenLop
		{
			get
			{
				return this._TenLop.Entity;
			}
			set
			{
				TenLop previousValue = this._TenLop.Entity;
				if (((previousValue != value) 
							|| (this._TenLop.HasLoadedOrAssignedValue == false)))
				{
					this.SendPropertyChanging();
					if ((previousValue != null))
					{
						this._TenLop.Entity = null;
						previousValue.SVs.Remove(this);
					}
					this._TenLop.Entity = value;
					if ((value != null))
					{
						value.SVs.Add(this);
						this._IDLop = value.IDLop;
					}
					else
					{
						this._IDLop = default(int);
					}
					this.SendPropertyChanged("TenLop");
				}
			}
		}
		
		public event PropertyChangingEventHandler PropertyChanging;
		
		public event PropertyChangedEventHandler PropertyChanged;
		
		protected virtual void SendPropertyChanging()
		{
			if ((this.PropertyChanging != null))
			{
				this.PropertyChanging(this, emptyChangingEventArgs);
			}
		}
		
		protected virtual void SendPropertyChanged(String propertyName)
		{
			if ((this.PropertyChanged != null))
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
	
	[global::System.Data.Linq.Mapping.TableAttribute(Name="dbo.TenLop")]
	public partial class TenLop : INotifyPropertyChanging, INotifyPropertyChanged
	{
		
		private static PropertyChangingEventArgs emptyChangingEventArgs = new PropertyChangingEventArgs(String.Empty);
		
		private int _IDLop;
		
		private string _TenLop1;
		
		private EntitySet<SV> _SVs;
		
    #region Extensibility Method Definitions
    partial void OnLoaded();
    partial void OnValidate(System.Data.Linq.ChangeAction action);
    partial void OnCreated();
    partial void OnIDLopChanging(int value);
    partial void OnIDLopChanged();
    partial void OnTenLop1Changing(string value);
    partial void OnTenLop1Changed();
    #endregion
		
		public TenLop()
		{
			this._SVs = new EntitySet<SV>(new Action<SV>(this.attach_SVs), new Action<SV>(this.detach_SVs));
			OnCreated();
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_IDLop", DbType="Int NOT NULL", IsPrimaryKey=true)]
		public int IDLop
		{
			get
			{
				return this._IDLop;
			}
			set
			{
				if ((this._IDLop != value))
				{
					this.OnIDLopChanging(value);
					this.SendPropertyChanging();
					this._IDLop = value;
					this.SendPropertyChanged("IDLop");
					this.OnIDLopChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Name="TenLop", Storage="_TenLop1", DbType="NVarChar(50)")]
		public string TenLop1
		{
			get
			{
				return this._TenLop1;
			}
			set
			{
				if ((this._TenLop1 != value))
				{
					this.OnTenLop1Changing(value);
					this.SendPropertyChanging();
					this._TenLop1 = value;
					this.SendPropertyChanged("TenLop1");
					this.OnTenLop1Changed();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.AssociationAttribute(Name="TenLop_SV", Storage="_SVs", ThisKey="IDLop", OtherKey="IDLop")]
		public EntitySet<SV> SVs
		{
			get
			{
				return this._SVs;
			}
			set
			{
				this._SVs.Assign(value);
			}
		}
		
		public event PropertyChangingEventHandler PropertyChanging;
		
		public event PropertyChangedEventHandler PropertyChanged;
		
		protected virtual void SendPropertyChanging()
		{
			if ((this.PropertyChanging != null))
			{
				this.PropertyChanging(this, emptyChangingEventArgs);
			}
		}
		
		protected virtual void SendPropertyChanged(String propertyName)
		{
			if ((this.PropertyChanged != null))
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
		
		private void attach_SVs(SV entity)
		{
			this.SendPropertyChanging();
			entity.TenLop = this;
		}
		
		private void detach_SVs(SV entity)
		{
			this.SendPropertyChanging();
			entity.TenLop = null;
		}
	}
}
#pragma warning restore 1591
