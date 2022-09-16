using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RESTClient
{
    [Serializable]
    public class Round
    {
        public Round(long id, string name)
        {
            this.id = id;
            this.name = name;
        }

        public Round(string name)
        {
            this.name = name;
        }

        public Round()
        {

        }

        [JsonProperty(PropertyName = "id")]
        public long id { get; set; }

        [JsonProperty(PropertyName = "name")]
        public string name { get; set; }

        public override string ToString()
        {
            return id + " " + name;
        }

    }


}
