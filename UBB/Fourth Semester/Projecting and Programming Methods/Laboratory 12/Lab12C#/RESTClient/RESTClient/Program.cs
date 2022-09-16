using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;

namespace RESTClient
{
    class MainClass
    {
        static HttpClient client = new HttpClient();

        public static void Main(string[] args)
        {
            try
            {
                RunAsync().Wait();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.ReadLine();

            }
        }


        static async Task RunAsync()
        {
            client.BaseAddress = new Uri("http://localhost:8081/competition/rounds");
            client.DefaultRequestHeaders.Accept.Clear();
            client.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
            Round round = new Round("367 m Round");

            //create
            /* try
             {
                 Round addedRound = await SaveRound("http://localhost:8081/competition/rounds", round);
                 Console.WriteLine("Added round: " + addedRound);
                 Console.ReadLine();
             }
             catch (Exception e)
             {
                 Console.WriteLine(e.Message);
                 Console.ReadLine();
             }*/

            //update
            /*  round.name = "400 m Round";
              try
              {
                  Round updatedRound = await UpdateRound("http://localhost:8081/competition/rounds/52", round);
                  Console.WriteLine("Updated round: " + updatedRound);
                  Console.ReadLine();
              }
              catch (Exception e)
              {
                  Console.WriteLine(e.Message);
                  Console.ReadLine();
              }*/

            //delete
            try
            {
                Round deletedRound = await DeleteRound("http://localhost:8081/competition/rounds/55");
                Console.WriteLine("Deleted round: " + deletedRound);
                Console.ReadLine();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.ReadLine();
            }


            //getById
            /*            try
                        {
                            Round res = await GetRoundAsync("http://localhost:8081/competition/rounds/54");
                            Console.WriteLine("Round: " + res);
                            Console.ReadLine();
                        }
                        catch (Exception e)
                        {
                            Console.WriteLine(e.Message);
                            Console.ReadLine();
                        }
            */


            //getAll
            /* try
             {
                 IList<Round> allRounds = await GetAllRoundsAsync("http://localhost:8081/competition/rounds");
                 foreach (var round1 in allRounds)
                     Console.WriteLine(round1);
                 Console.ReadLine();
             }
             catch (Exception e)
             {
                 Console.WriteLine(e.Message);
                 Console.ReadLine();
             }*/


        }

        static async Task<Round> SaveRound(string path, Round round)
        {
            string r = null;
            Round result = null;
            String serializedRound = Newtonsoft.Json.JsonConvert.SerializeObject(round);
            var content = new StringContent(serializedRound, Encoding.UTF8, "application/json");
            var response = await client.PostAsync(path, content);
            if (response.IsSuccessStatusCode)
            {
                r = await response.Content.ReadAsStringAsync();
                result = Newtonsoft.Json.JsonConvert.DeserializeObject<Round>(r);
            }
            else
            {
                throw new Exception("Could not save round!");
            }
            return result;
        }

        static async Task<Round> UpdateRound(string path, Round round)
        {
            string r = null;
            Round result = null;
            String serializedRide = Newtonsoft.Json.JsonConvert.SerializeObject(round);
            var content = new StringContent(serializedRide, Encoding.UTF8, "application/json");
            var response = await client.PutAsync(path, content);
            if (response.IsSuccessStatusCode)
            {
                r = await response.Content.ReadAsStringAsync();
                result = Newtonsoft.Json.JsonConvert.DeserializeObject<Round>(r);
            }
            else { throw new Exception("Could not update round!"); }
            return result;
        }

        static async Task<Round> DeleteRound(string path)
        {
            string r = null;
            Round result = null;
            var response = await client.DeleteAsync(path);
            if (response.IsSuccessStatusCode)
            {
                r = await response.Content.ReadAsStringAsync();
                result = Newtonsoft.Json.JsonConvert.DeserializeObject<Round>(r);
            }
            else { throw new Exception("Could not delete round!"); }
            return result;
        }

        static async Task<Round> GetRoundAsync(string path)
        {
            String r = null;
            Round result = null;
            HttpResponseMessage response = await client.GetAsync(path);
            if (response.IsSuccessStatusCode)
            {
                r = await response.Content.ReadAsStringAsync();
                result = Newtonsoft.Json.JsonConvert.DeserializeObject<Round>(r);
            }
            else { throw new Exception("Could not find round!"); }
            return result;
        }

        static async Task<IList<Round>> GetAllRoundsAsync(string path)
        {
            string r = null;
            IList<Round> rides = new List<Round>();
            var response = await client.GetAsync(path);
            if (response.IsSuccessStatusCode)
            {
                r = await response.Content.ReadAsStringAsync();
                rides = Newtonsoft.Json.JsonConvert.DeserializeObject<IList<Round>>(r);
            }
            else
            {
                throw new Exception("Could not find rounds!");
            }
            return rides;
        }

    }

}
