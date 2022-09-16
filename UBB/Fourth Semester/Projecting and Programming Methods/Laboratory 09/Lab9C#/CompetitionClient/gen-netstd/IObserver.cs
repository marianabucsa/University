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

public partial class IObserver
{
  public interface IAsync
  {
    global::System.Threading.Tasks.Task update(CancellationToken cancellationToken = default);

  }


  public class Client : TBaseClient, IDisposable, IAsync
  {
    public Client(TProtocol protocol) : this(protocol, protocol)
    {
    }

    public Client(TProtocol inputProtocol, TProtocol outputProtocol) : base(inputProtocol, outputProtocol)
    {
    }

    public async global::System.Threading.Tasks.Task update(CancellationToken cancellationToken = default)
    {
      await send_update(cancellationToken);
    }

    public async global::System.Threading.Tasks.Task send_update(CancellationToken cancellationToken = default)
    {
      await OutputProtocol.WriteMessageBeginAsync(new TMessage("update", TMessageType.Oneway, SeqId), cancellationToken);
      
      var tmp25 = new InternalStructs.update_args() {
      };
      
      await tmp25.WriteAsync(OutputProtocol, cancellationToken);
      await OutputProtocol.WriteMessageEndAsync(cancellationToken);
      await OutputProtocol.Transport.FlushAsync(cancellationToken);
    }

  }

  public class AsyncProcessor : ITAsyncProcessor
  {
    private readonly IAsync _iAsync;
    private readonly ILogger<AsyncProcessor> _logger;

    public AsyncProcessor(IAsync iAsync, ILogger<AsyncProcessor> logger = default)
    {
      _iAsync = iAsync ?? throw new ArgumentNullException(nameof(iAsync));
      _logger = logger;
      processMap_["update"] = update_ProcessAsync;
    }

    protected delegate global::System.Threading.Tasks.Task ProcessFunction(int seqid, TProtocol iprot, TProtocol oprot, CancellationToken cancellationToken);
    protected Dictionary<string, ProcessFunction> processMap_ = new Dictionary<string, ProcessFunction>();

    public async Task<bool> ProcessAsync(TProtocol iprot, TProtocol oprot)
    {
      return await ProcessAsync(iprot, oprot, CancellationToken.None);
    }

    public async Task<bool> ProcessAsync(TProtocol iprot, TProtocol oprot, CancellationToken cancellationToken)
    {
      try
      {
        var msg = await iprot.ReadMessageBeginAsync(cancellationToken);

        processMap_.TryGetValue(msg.Name, out ProcessFunction fn);

        if (fn == null)
        {
          await TProtocolUtil.SkipAsync(iprot, TType.Struct, cancellationToken);
          await iprot.ReadMessageEndAsync(cancellationToken);
          var x = new TApplicationException (TApplicationException.ExceptionType.UnknownMethod, "Invalid method name: '" + msg.Name + "'");
          await oprot.WriteMessageBeginAsync(new TMessage(msg.Name, TMessageType.Exception, msg.SeqID), cancellationToken);
          await x.WriteAsync(oprot, cancellationToken);
          await oprot.WriteMessageEndAsync(cancellationToken);
          await oprot.Transport.FlushAsync(cancellationToken);
          return true;
        }

        await fn(msg.SeqID, iprot, oprot, cancellationToken);

      }
      catch (IOException)
      {
        return false;
      }

      return true;
    }

    public async global::System.Threading.Tasks.Task update_ProcessAsync(int seqid, TProtocol iprot, TProtocol oprot, CancellationToken cancellationToken)
    {
      var tmp26 = new InternalStructs.update_args();
      await tmp26.ReadAsync(iprot, cancellationToken);
      await iprot.ReadMessageEndAsync(cancellationToken);
      try
      {
        await _iAsync.update(cancellationToken);
      }
      catch (TTransportException)
      {
        throw;
      }
      catch (Exception tmp28)
      {
        var tmp29 = $"Error occurred in {GetType().FullName}: {tmp28.Message}";
        if(_logger != null)
          _logger.LogError("{Exception}, {Message}", tmp28, tmp29);
        else
          Console.Error.WriteLine(tmp29);
      }
    }

  }

  public class InternalStructs
  {

    public partial class update_args : TBase
    {

      public update_args()
      {
      }

      public update_args DeepCopy()
      {
        var tmp30 = new update_args();
        return tmp30;
      }

      public async global::System.Threading.Tasks.Task ReadAsync(TProtocol iprot, CancellationToken cancellationToken)
      {
        iprot.IncrementRecursionDepth();
        try
        {
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
              default: 
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
                break;
            }

            await iprot.ReadFieldEndAsync(cancellationToken);
          }

          await iprot.ReadStructEndAsync(cancellationToken);
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
          var tmp31 = new TStruct("update_args");
          await oprot.WriteStructBeginAsync(tmp31, cancellationToken);
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
        if (!(that is update_args other)) return false;
        if (ReferenceEquals(this, other)) return true;
        return true;
      }

      public override int GetHashCode() {
        int hashcode = 157;
        unchecked {
        }
        return hashcode;
      }

      public override string ToString()
      {
        var tmp32 = new StringBuilder("update_args(");
        tmp32.Append(')');
        return tmp32.ToString();
      }
    }

  }

}
