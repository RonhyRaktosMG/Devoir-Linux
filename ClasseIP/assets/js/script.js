$(document).ready(()=>{
    var div_result = $("#result");
    var div_result_ok = $(".resultok");
    var entry = $("#ip_entry");
    
    div_result_ok.fadeIn();
    entry.on("focus", ()=>{
        div_result.fadeOut()
    })
   
})