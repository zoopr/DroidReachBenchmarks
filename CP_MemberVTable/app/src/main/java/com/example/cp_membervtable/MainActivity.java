package com.example.cp_membervtable;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.example.cp_membervtable.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    // Used to load the 'cp_membervtable' library on application startup.
    static {
        System.loadLibrary("cp_membervtable");
    }

    private ActivityMainBinding binding;
    private long native_obj_ptr;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        native_obj_ptr = build_obj();
        binding.sampleText.setText("C3 instantiated");

        Button b = binding.button;
        b.setOnClickListener(this);
    }

    public void onClick(View view) {
        int v = member_class_method(native_obj_ptr);

        TextView tv = findViewById(R.id.sample_text);
        tv.setText(String.valueOf(v));
    }

    public native long build_obj();
    public native int member_class_method(long native_obj);
}