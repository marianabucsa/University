/**
 * <auto-generated>
 * Autogenerated by Thrift Compiler (0.16.0)
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 * </auto-generated>
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.Extensions.Logging;
using Thrift;
using Thrift.Collections;

using Thrift.Protocol;
using Thrift.Protocol.Entities;
using Thrift.Protocol.Utilities;
using Thrift.Transport;
using Thrift.Transport.Client;
using Thrift.Transport.Server;
using Thrift.Processor;


#nullable disable                // suppress C# 8.0 nullable contexts (we still support earlier versions)
#pragma warning disable IDE0079  // remove unnecessary pragmas
#pragma warning disable IDE1006  // parts of the code use IDL spelling
#pragma warning disable IDE0083  // pattern matching "that is not SomeType" requires net5.0 but we still support earlier versions


public partial class Round : TBase
{

  public long Id { get; set; }

  public string Name { get; set; }

  public Round()
  {
  }

  public Round(long id, string name) : this()
  {
    this.Id = id;
    this.Name = name;
  }

  public Round DeepCopy()
  {
    var tmp10 = new Round();
    tmp10.Id = this.Id;
    if((Name != null))
    {
      tmp10.Name = this.Name;
    }
    return tmp10;
  }

  public async global::System.Threading.Tasks.Task ReadAsync(TProtocol iprot, CancellationToken cancellationToken)
  {
    iprot.IncrementRecursionDepth();
    try
    {
      bool isset_id = false;
      bool isset_name = false;
      TField field;
      await iprot.ReadStructBeginAsync(cancellationToken);
      while (true)
      {
        field = await iprot.ReadFieldBeginAsync(cancellationToken);
        if (field.Type == TType.Stop)
        {
          break;
        }

        switch (field.ID)
        {
          case 1:
            if (field.Type == TType.I64)
            {
              Id = await iprot.ReadI64Async(cancellationToken);
              isset_id = true;
            }
            else
            {
              await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
            }
            break;
          case 2:
            if (field.Type == TType.String)
            {
              Name = await iprot.ReadStringAsync(cancellationToken);
              isset_name = true;
            }
            else
            {
              await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
            }
            break;
          default: 
            await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
            break;
        }

        await iprot.ReadFieldEndAsync(cancellationToken);
      }

      await iprot.ReadStructEndAsync(cancellationToken);
      if (!isset_id)
      {
        throw new TProtocolException(TProtocolException.INVALID_DATA);
      }
      if (!isset_name)
      {
        throw new TProtocolException(TProtocolException.INVALID_DATA);
      }
    }
    finally
    {
      iprot.DecrementRecursionDepth();
    }
  }

  public async global::System.Threading.Tasks.Task WriteAsync(TProtocol oprot, CancellationToken cancellationToken)
  {
    oprot.IncrementRecursionDepth();
    try
    {
      var tmp11 = new TStruct("Round");
      await oprot.WriteStructBeginAsync(tmp11, cancellationToken);
      var tmp12 = new TField();
      tmp12.Name = "id";
      tmp12.Type = TType.I64;
      tmp12.ID = 1;
      await oprot.WriteFieldBeginAsync(tmp12, cancellationToken);
      await oprot.WriteI64Async(Id, cancellationToken);
      await oprot.WriteFieldEndAsync(cancellationToken);
      if((Name != null))
      {
        tmp12.Name = "name";
        tmp12.Type = TType.String;
        tmp12.ID = 2;
        await oprot.WriteFieldBeginAsync(tmp12, cancellationToken);
        await oprot.WriteStringAsync(Name, cancellationToken);
        await oprot.WriteFieldEndAsync(cancellationToken);
      }
      await oprot.WriteFieldStopAsync(cancellationToken);
      await oprot.WriteStructEndAsync(cancellationToken);
    }
    finally
    {
      oprot.DecrementRecursionDepth();
    }
  }

  public override bool Equals(object that)
  {
    if (!(that is Round other)) return false;
    if (ReferenceEquals(this, other)) return true;
    return global::System.Object.Equals(Id, other.Id)
      && global::System.Object.Equals(Name, other.Name);
  }

  public override int GetHashCode() {
    int hashcode = 157;
    unchecked {
      hashcode = (hashcode * 397) + Id.GetHashCode();
      if((Name != null))
      {
        hashcode = (hashcode * 397) + Name.GetHashCode();
      }
    }
    return hashcode;
  }

  public override string ToString()
  {
    var tmp13 = new StringBuilder("Round(");
    tmp13.Append(", Id: ");
    Id.ToString(tmp13);
    if((Name != null))
    {
      tmp13.Append(", Name: ");
      Name.ToString(tmp13);
    }
    tmp13.Append(')');
    return tmp13.ToString();
  }
}

